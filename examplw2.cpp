#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

map<char, vector<string>> grammar;  // 文法产生式
map<char, set<char>> firstSets;     // First 集合
map<char, set<char>> followSets;    // Follow 集合
set<char> terminals;                // 终结符集合
char startSymbol;                   // 开始符号

// 判断是否为终结符
bool isTerminal(char symbol) {
    return islower(symbol) || isdigit(symbol) || ispunct(symbol);
}
// 初始化 Follow 集合
void initializeFollowSets() {
    for (auto &rule : grammar) {
        char nonTerminal = rule.first;
        followSets[nonTerminal] = {};  // 初始化 Follow 集合为空
    }
    followSets[startSymbol].insert('$');  // 开始符号 Follow 集合包含终止符号 '$'
}
// 计算 First 集合
void computeFirst(char nonTerminal) {
    for (string production : grammar[nonTerminal]) {
        bool containsEpsilon = true;

        for (char symbol : production) {
            if (isTerminal(symbol)) {
                firstSets[nonTerminal].insert(symbol);  // 终结符直接加入 First 集合
                containsEpsilon = false;
                break;
            } else {
                computeFirst(symbol);  // 递归处理非终结符
                for (char s : firstSets[symbol]) {
                    if (s != 'ε') {
                        firstSets[nonTerminal].insert(s);
                    }
                }
                if (firstSets[symbol].find('ε') == firstSets[symbol].end()) {
                    containsEpsilon = false;
                    break;
                }
            }
        }
        if (containsEpsilon) {
            firstSets[nonTerminal].insert('ε');  // 处理空串 ε
        }
    }
}

// 计算 Follow 集合
void computeFollow() {
    bool updated = true;
    while (updated) {
        updated = false;
        for (auto &rule : grammar) {
            char A = rule.first;  // 左部非终结符
            for (string production : rule.second) {
                int len = production.length();
                for (int i = 0; i < len; i++) {
                    char B = production[i];  // 右部符号
                    if (!isTerminal(B)) {  // 只处理非终结符
                        bool containsEpsilon = true;
                        // 处理 B 后面的符号
                        for (int j = i + 1; j < len && containsEpsilon; j++) {
                            char beta = production[j];
                            if (isTerminal(beta)) {
                                if (followSets[B].insert(beta).second) {
                                    updated = true;
                                }
                                containsEpsilon = false;
                            } else {
                                for (char symbol : firstSets[beta]) {
                                    if (symbol != 'ε' && followSets[B].insert(symbol).second) {
                                        updated = true;
                                    }
                                }
                                if (firstSets[beta].find('ε') == firstSets[beta].end()) {
                                    containsEpsilon = false;
                                }
                            }
                        }
                        // 如果 B 是产生式的最后一个符号，或者 β 可以导出空串
                        if (containsEpsilon || i == len - 1) {
                            for (char symbol : followSets[A]) {
                                if (followSets[B].insert(symbol).second) {
                                    updated = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// 打印 Follow 集合
void printFollowSets() {
    for (auto &set : followSets) {
        cout << "Follow(" << set.first << ") = { ";
        for (char s : set.second) {
            cout << s << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    int n;
    cout << "请输入文法中产生式的数量: ";
    cin >> n;
    cout << "请输入产生式（形式为 A->BC 或 A->a 等，其中 A 为非终结符）:\n";
    for (int i = 0; i < n; i++) {
        char nonTerminal;
        string arrow, production;
        cin >> nonTerminal >> arrow >> production;
        grammar[nonTerminal].push_back(production);
        // 记录终结符
        for (char c : production) {
            if (isTerminal(c)) {
                terminals.insert(c);
            }
        }
    }
    cout << "请输入文法的开始符号: ";
    cin >> startSymbol;
    // 初始化并计算 First 集合
    for (auto &rule : grammar) {
        computeFirst(rule.first);
    }
    // 初始化 Follow 集合
    initializeFollowSets();
    // 计算 Follow 集合
    computeFollow();
    // 打印 Follow 集合
    printFollowSets();
    return 0;
}
