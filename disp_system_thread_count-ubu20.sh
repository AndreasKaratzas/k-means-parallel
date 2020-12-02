
#!/bin/bash

cat /proc/cpuinfo | grep siblings | uniq
