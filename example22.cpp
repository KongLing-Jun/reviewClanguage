#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::find

using namespace std;

vector<string> noTerminal;   // 非终结符集合
vector<string> terminal;     // 终结符集合
string grammarRules[100][2]; // 用于存储产生式

// 消除左递归
void eliminate(string grammar) {
    size_t pipeIndex = grammar.find("|");
    size_t arrowIndex = grammar.find("->");

    if (pipeIndex == string::npos || arrowIndex == string::npos) {
        cout << "错误：产生式格式不正确" << endl;
        return;
    }

    string leftSymbol = grammar.substr(0, arrowIndex);
    leftSymbol.erase(leftSymbol.find_last_not_of(" \n\r\t") + 1); // 去除空白字符

    string rightSymbol = grammar.substr(arrowIndex + 2, pipeIndex - (arrowIndex + 2));
    rightSymbol.erase(rightSymbol.find_last_not_of(" \n\r\t") + 1); // 去除空白字符

    // 检查是否存在左递归
    if (rightSymbol.substr(0, leftSymbol.length()) == leftSymbol) {
        // 存在左递归，进行消除
        string newNonTerminal = leftSymbol;
        transform(newNonTerminal.begin(), newNonTerminal.end(), newNonTerminal.begin(), ::tolower); // 创建新的非终结符

        if (find(noTerminal.begin(), noTerminal.end(), newNonTerminal) == noTerminal.end()) {
            noTerminal.push_back(newNonTerminal); // 将新的非终结符加入到集合中
        }
        if (find(terminal.begin(), terminal.end(), "-") == terminal.end()) {
            terminal.push_back("-"); // 添加终结符 "-"（表示空串）
        }

        // 构造新的产生式
        string newProduction = rightSymbol.substr(leftSymbol.length()) + newNonTerminal;
        grammarRules[find(noTerminal.begin(), noTerminal.end(), newNonTerminal) - noTerminal.begin()][0] = newProduction;
        grammarRules[find(noTerminal.begin(), noTerminal.end(), newNonTerminal) - noTerminal.begin()][1] = "-";

        // 修改原产生式
        string remainingProduction = grammar.substr(pipeIndex + 1);
        remainingProduction.erase(remainingProduction.find_last_not_of(" \n\r\t") + 1); // 去除空白字符
        remainingProduction += newNonTerminal;

        grammarRules[find(noTerminal.begin(), noTerminal.end(), leftSymbol) - noTerminal.begin()][0] = remainingProduction;
    } else {
        // 不存在左递归，直接使用原产生式
        grammarRules[find(noTerminal.begin(), noTerminal.end(), leftSymbol) - noTerminal.begin()][0] = 
        grammarRules[find(noTerminal.begin(), noTerminal.end(), leftSymbol) - noTerminal.begin()][0];
        grammarRules[find(noTerminal.begin(), noTerminal.end(), leftSymbol) - noTerminal.begin()][1] = 
        grammarRules[find(noTerminal.begin(), noTerminal.end(), leftSymbol) - noTerminal.begin()][1];
    }
}

int main() {
    // 示例：定义非终结符
    noTerminal.push_back("S");
    noTerminal.push_back("A");

    // 示例：调用 eliminate 函数
    string grammar = "S -> Sa | b";
    eliminate(grammar);

    // 输出结果
    for (int i = 0; i < noTerminal.size(); i++) {
        cout << noTerminal[i] << " -> " << grammarRules[i][0] << " | " << grammarRules[i][1] << endl;
    }

    return 0;
}
