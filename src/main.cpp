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
  std::string name_task = "";
  std::string new_name_task = "";
  std::time_t time_start = 0;
  std::time_t time_end = 0;
  std::time_t time_spent = 0;
  bool first_task = true;
  int count_task = 0;

  do {
    std::cout << "Enter the command (begin/end/status/exit)" << std::endl;
    std::cin >> command;
    if (!command.empty()) {
      if (command == begin) {
        std::cout << "begin" << std::endl;
        std::cout << "Enter the name of the task" << std::endl;
        std::cin >> new_name_task;
        count_task++;
        time_start = std::time(nullptr);
        std::cout << "time_start " << time_start << std::endl;
        /**
         * TODO Счет времени при начало task и началом нового task = 0
         **/
        if (count_task > 1)
        // if ((name_task != new_name_task))
        {
          std::cout << "Task " << name_task << " finish." << std::endl;
          std::cout << "The task began " << new_name_task << std::endl;
          time_spent = time_end - time_start;
          std::cout << "time_spent " << time_spent << std::endl;
          archive_task.insert(std::make_pair(new_name_task, time_spent));
          name_task = new_name_task;
        } else {
          time_spent = time_end - time_start;
          std::cout << "time_spent " << time_spent << std::endl;
          archive_task.insert(std::make_pair(new_name_task, time_spent));
        }
        task = true;
      } else if (command == end) {
        time_end = std::time(nullptr);
        time_spent = time_end - time_start;
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
    time_end = std::time(nullptr);
    std::cout << "time_end " << time_end << std::endl;
  } while (true);
  for (std::map<std::string, std::time_t>::iterator it = archive_task.begin(); it != archive_task.end(); it++) {
    std::cout << "Task - " << it->first << "; Time - " << it->second << std::endl;
  }
  return 0;
}
