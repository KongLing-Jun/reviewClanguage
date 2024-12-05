#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// 文法的产生式
struct Production {
    char non_terminal;
    string production;
};

// First集的获取函数
set<char> getFirst(char symbol, map<char, set<char>> &firstSets, vector<Production> &productions) {
    set<char> firstSet;
    
    // 如果是终结符，直接返回它自身
    if (!isupper(symbol)) {
        firstSet.insert(symbol);
        return firstSet;
    }

    // 遍历产生式找到以该符号开头的产生式
    for (auto prod : productions) {
        if (prod.non_terminal == symbol) {
            char firstSymbol = prod.production[0];
            if (!isupper(firstSymbol)) {
                firstSet.insert(firstSymbol);
            } else {
                // 递归查找First集
                set<char> tempFirst = getFirst(firstSymbol, firstSets, productions);
                firstSet.insert(tempFirst.begin(), tempFirst.end());
            }
        }
    }
    return firstSet;
}

// Follow集的获取函数
set<char> getFollow(char nonTerminal, map<char, set<char>> &followSets, map<char, 
                    set<char>> &firstSets, vector<Production> &productions) {
    set<char> followSet;
    // 初始时将$加入到开始符号的Follow集中
    if (nonTerminal == 'S') {
        followSet.insert('$');
    }
    // 遍历产生式
    for (auto prod : productions) {
        string production = prod.production;
        for (size_t i = 0; i < production.size(); i++) {
            if (production[i] == nonTerminal) {
                if (i + 1 < production.size()) {
                    char nextSymbol = production[i + 1];
                    if (!isupper(nextSymbol)) {
                        followSet.insert(nextSymbol);
                    } else {
                        set<char> firstOfNext = firstSets[nextSymbol];
                        followSet.insert(firstOfNext.begin(), firstOfNext.end());
                        followSet.erase('ϵ');  // 移除空串ϵ
                    }
                }
                if (i + 1 == production.size() || firstSets[production[i + 1]].count('ϵ')) {
                    set<char> followOfLHS = followSets[prod.non_terminal];
                    followSet.insert(followOfLHS.begin(), followOfLHS.end());
                }
            }
        }
    }
    return followSet;
}

// 构建预测分析表
void constructParseTable(map<char, map<char, string>> &parseTable, vector<Production> &productions,
                         map<char, set<char>> &firstSets, map<char, set<char>> &followSets) {
    for (auto prod : productions) {
        char nonTerminal = prod.non_terminal;
        string production = prod.production;
        set<char> firstSet = firstSets[production[0]];
        for (auto terminal : firstSet) {
            if (terminal != 'ϵ') {
                parseTable[nonTerminal][terminal] = production;
            }
        }
        if (firstSet.count('ϵ')) {
            set<char> followSet = followSets[nonTerminal];
            for (auto terminal : followSet) {
                parseTable[nonTerminal][terminal] = production;
            }
        }
    }
}

int main() {
    // 定义文法的产生式
    vector<Production> productions = {
        {'S', "AB"},
        {'A', "aA"},
        {'A', "ϵ"},
        {'B', "bB"},
        {'B', "ϵ"}
    };
    // 定义First集合和Follow集合
    map<char, set<char>> firstSets;
    map<char, set<char>> followSets;

    // 计算First集合
    for (auto prod : productions) {
        char nonTerminal = prod.non_terminal;
        set<char> firstSet = getFirst(nonTerminal, firstSets, productions);
        firstSets[nonTerminal] = firstSet;
    }
    // 计算Follow集合
    for (auto prod : productions) {
        char nonTerminal = prod.non_terminal;
        set<char> followSet = getFollow(nonTerminal, followSets, firstSets, productions);
        followSets[nonTerminal] = followSet;
    }
    // 生成预测分析表
    map<char, map<char, string>> parseTable;
    constructParseTable(parseTable, productions, firstSets, followSets);
    // 输出预测分析表
    cout << "预测分析表:" << endl;
    for (auto row : parseTable) {
        for (auto cell : row.second) {
            cout << "M[" << row.first << ", " << cell.first << "] = " << cell.second << endl;
        }
    }
    return 0;
}
