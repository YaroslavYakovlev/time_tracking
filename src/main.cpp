#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>

bool task = false;

int main() {
  std::cout << "Time tracking" << std::endl;
  const std::string begin = "begin";
  const std::string end = "end";
  const std::string status = "status";
  const std::string exit = "exit";
  std::map<std::string, std::time_t> archive_task;
  std::string command = "";
  std::string new_name_task = "";
  std::string name_task = "";
  std::time_t time_start = 0;
  std::time_t time_start_old = 0;
  std::time_t time_end = 0;
  std::time_t time_spent = 0;
  bool first_task = true;
  int count_task = 0;

  do {
    std::cout << "Enter the command (begin/end/status/exit)" << std::endl;
    std::cin >> command;
    if (!command.empty()) {
      if (command == begin) {
        std::cout << "Enter the name of the task" << std::endl;
        std::cin >> new_name_task;
        time_start_old = time_start;
        count_task++;
        time_start = std::time(nullptr);
        // if (count_task == 1) {
        //   name_task = new_name_task;
        //   // archive_task.push_back(name_task);
        // }
        if (count_task >= 1) {
          time_end = std::time(nullptr);
          time_spent = time_end - time_start_old;
          std::cout << "time_spent " << time_spent << std::endl;
          if (count_task > 1) {
            std::cout << "Task " << name_task << " finish." << std::endl;
            std::cout << "The task began " << new_name_task << std::endl;

            name_task = new_name_task;
          }
          archive_task.insert(std::make_pair(new_name_task, time_spent));
        }
        // task = true;
      } else if (command == end) {
        time_end = std::time(nullptr);
        time_spent = time_end - time_start_old;
        archive_task.insert(std::make_pair(name_task, time_spent));
      } else if (command == status) {
        for (std::map<std::string, std::time_t>::iterator it = archive_task.begin(); it != archive_task.end(); it++) {
          std::cout << "Task - " << it->first << "; Time - " << it->second << std::endl;
        }
      } else if (command == exit) {
        break;
      } else {
        std::cout << "There is no such team" << std::endl;
      }
    } else {
      std::cout << "The team cannot be empty" << std::endl;
    }

  } while (true);
  for (std::map<std::string, std::time_t>::iterator it = archive_task.begin(); it != archive_task.end(); it++) {
    std::cout << "Task - " << it->first << "; Time - " << it->second << std::endl;
  }
  return 0;
}
