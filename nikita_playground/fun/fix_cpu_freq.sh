FREQ=2300000

echo performance | tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor
echo ${FREQ} | tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_max_freq
echo ${FREQ} | tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_min_freq
