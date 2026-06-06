ScriptDirectory="$(cd "$(dirname "$0")" && pwd)"

rm -rf bin
clear
make all -j$(nproc)
./bin/executable
