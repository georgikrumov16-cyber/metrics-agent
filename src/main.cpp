#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/statvfs.h>
#include "httplib.h"

using namespace std;
// ---------------- CPU USAGE ----------------
double getCPUUsage() {
    long user, nice, system, idle;
    long total1, total2, idle1, idle2;

    ifstream stat1("/proc/stat");
    string cpu;
    stat1 >> cpu >> user >> nice >> system >> idle;
    stat1.close();

    idle1 = idle;
    total1 = user + nice + system + idle;


    usleep(1000000); // sleep 1000ms
    usleep(100000); // sleep 100ms


    ifstream stat2("/proc/stat");
    stat2 >> cpu >> user >> nice >> system >> idle;
    stat2.close();

    idle2 = idle;
    total2 = user + nice + system + idle;

    double totalDiff = total2 - total1;
    double idleDiff = idle2 - idle1;

    return (1.0 - idleDiff / totalDiff) * 100.0;
}

// ---------------- MEMORY USAGE ----------------
double getMemoryUsage() {
    ifstream meminfo("/proc/meminfo");
    string key;
    long value;
    string unit;

    long memTotal = 0;
    long memAvailable = 0;

    while (meminfo >> key >> value >> unit) {
        if (key == "MemTotal:") memTotal = value;
        if (key == "MemAvailable:") memAvailable = value;
    }

    return (1.0 - (double)memAvailable / memTotal) * 100.0;
}

// ---------------- DISK USAGE ----------------
double getDiskUsage() {
    struct statvfs stat;

    if (statvfs("/", &stat) != 0) {
        return -1;
    }

    double total = stat.f_blocks * stat.f_frsize;
    double free = stat.f_bfree * stat.f_frsize;

    return (1.0 - free / total) * 100.0;
}

// ---------------- MAIN ----------------
int main() {
    httplib::Server svr;

svr.Get("/metrics", [](const httplib::Request&, httplib::Response& res) {
    double cpu = getCPUUsage();
    double mem = getMemoryUsage();
    double disk = getDiskUsage();

    string body = "";
    body += "cpu_usage " + to_string(cpu) + "\n";
    body += "memory_usage " + to_string(mem) + "\n";
    body += "disk_usage " + to_string(disk) + "\n";

    res.set_content(body, "text/plain");
});

cout << "Server running on http://localhost:8080/metrics" << endl;
svr.listen("0.0.0.0", 8080);

}
