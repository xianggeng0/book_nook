# 管理系统

这是一个用C++编写的管理系统，旨在通过控制台界面提供员工信息管理功能。该系统支持三种类型的员工：普通员工、经理和老板，每种类型都有特定的职责描述。

## 功能详述

- **添加员工**：用户可以输入员工的ID、姓名和职位来添加新员工。
- **显示员工信息**：系统能够展示所有员工的详细信息，包括ID、姓名、职位和职责。
- **删除员工**：用户可以通过输入员工ID来删除特定员工的记录。
- **修改员工信息**：用户可以更新现有员工的ID、姓名和职位信息。
- **搜索员工**：系统提供按员工ID或姓名搜索的功能，方便快速定位员工信息。
- **排序员工**：员工信息可以按照ID升序或降序进行排序，以便用户查看。
- **清除数据**：用户可以选择清除所有员工数据，通常用于重置系统。

## 开始使用

要运行此系统，请按照以下步骤操作：

1. **获取代码**：克隆代码仓库或直接下载源代码文件。
2. **编译代码**：使用支持C++11或更高版本的编译器编译源代码。
3. **运行程序**：编译完成后，运行生成的可执行文件。

## 依赖和环境

- 需要一个C++编译器，如GCC或Clang。
- 程序使用标准库中的文件流和字符串处理功能，无需额外的第三方库。


## 核心功能代码

- **员工基类** (`Worker`)：
  ```cpp
  class Worker {
  public:
      virtual void sI() = 0; // 纯虚函数，用于显示员工信息
      virtual string get_DeptN() = 0; // 纯虚函数，用于获取部门名称
      int m_Id;
      string m_Name;
      int m_DeptId;
  };
  ```

- **员工信息显示** (`Employee::sI`)：
  ```cpp
  void Employee::sI() {
      cout << "Employee's number: " << this->m_Id
           << "\tName of employee: " << this->m_Name
           << "\tPosition: " << this->get_DeptN()
           << "\tDuty: Complete the tasks assigned by the manager" << endl;
  }
  ```

- **添加员工** (`WM::Add_Emp`)：
  ```cpp
  void WM::Add_Emp() {
      int ADDNUM = 0;
      cin >> ADDNUM;
      // ...省略添加员工的代码...
      this->save(); // 保存员工信息到文件
  }
  ```

- **保存员工信息到文件** (`WM::save`)：
  ```cpp
  void WM::save() {
      ofstream ofs;
      ofs.open(FILENAME, ios::out);
      for (int j = 0; j < this->m_EmpNum; j++) {
          ofs << this->m_EmpArray[j]->m_Id << " "
              << this->m_EmpArray[j]->m_Name << " "
              << this->m_EmpArray[j]->m_DeptId << endl;
      }
      ofs.close();
  }
  ```

- **主菜单显示** (`WM::SHOW_MENU`)：
  ```cpp
  void WM::SHOW_MENU() {
      cout << "Welcome to the employee management system!" << endl;
      // ...省略其他菜单选项...
      cout << "0. Exit the management program" << endl;
  }
  ```

- **程序入口** (`main`)：
  ```cpp
  int main() {
      WorkerManager w_m;
      int n = 0;
      while (true) {
          w_m.SHOW_MENU();
          scanf("%d", &n);
          // ...省略switch-case处理用户输入...
      }
  }
  ```


## 联系方式

如果您在使用过程中遇到任何问题，或有任何建议和反馈，欢迎通过以下方式联系我们：

- 邮箱：[xianggeng00@gmail.com]

我们期待您的宝贵意见，共同改进这个管理系统。
