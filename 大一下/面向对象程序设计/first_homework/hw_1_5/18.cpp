#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <iomanip>  

using namespace std;


struct Student {
    string id;           
    string name;         
    double scores[8];    
    double average;      

    
    void calculateAverage() {
        double sum = 0;
        for (int i = 0; i < 8; i++) {
            sum += scores[i];
        }
        average = sum / 8.0;
    }
};


bool compareStudents(const Student& a, const Student& b) {
    return a.average > b.average;
}

int main() {
    int count;
    cout << "请输入学生人数: ";
    cin >> count;

    vector<Student> students(count);

    
    for (int i = 0; i < count; i++) {
        cout << "\n--- 请输入第 " << i + 1 << " 位学生的信息 ---\n";
        cout << "学号: ";
        cin >> students[i].id;
        cout << "姓名: ";
        cin >> students[i].name;
        cout << "请输入 8 门课的成绩: ";
        for (int j = 0; j < 8; j++) {
            cin >> students[i].scores[j];
        }
        
        students[i].calculateAverage();
    }

    sort(students.begin(), students.end(), compareStudents);

    
    cout << "\n================ 成绩排名（按平均分从高到低） ================\n";
    cout << left << setw(12) << "学号" << setw(10) << "姓名";
    for (int j = 1; j <= 8; j++) cout << "课" << j << "  ";
    cout << "平均分" << endl;
    cout << "------------------------------------------------------------\n";

    for (const auto& s : students) {
        cout << left << setw(12) << s.id << setw(10) << s.name;
        for (int j = 0; j < 8; j++) {
            cout << fixed << setprecision(1) << s.scores[j] << " ";
        }
        cout << " | " << setprecision(2) << s.average << endl;
    }

    return 0;
}