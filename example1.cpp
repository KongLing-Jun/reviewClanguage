#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>

using namespace std;

// 定义文法结构
map<char, vector<string>> grammar;  // 非终结符 -> 产生式列表
map<char, set<char>> firstSets;     // 非终结符 -> First 集合
set<char> terminals;                // 终结符集合

// 判断是否为终结符
bool isTerminal(char symbol) {
    return islower(symbol) || isdigit(symbol) || ispunct(symbol);
}

// 初始化 First 集合
void initializeFirstSets() {
    for (auto &rule : grammar) {
        char nonTerminal = rule.first;
        firstSets[nonTerminal] = {};  // 初始化 First 集合为空
    }
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

// 打印 First 集合
void printFirstSets() {
    for (auto &set : firstSets) {
        cout << "First(" << set.first << ") = { ";
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
    initializeFirstSets();
    for (auto &rule : grammar) {
        computeFirst(rule.first);  // 计算每个非终结符的 First 集合
    }
    printFirstSets();
    return 0;

}


