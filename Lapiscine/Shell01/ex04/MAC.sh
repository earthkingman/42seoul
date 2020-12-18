 ifconfig | grep 'ether [[:xdigit:]]' | awk '{print $2}'
