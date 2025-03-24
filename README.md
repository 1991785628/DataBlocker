# DataBlocker
一个简单的根据数据包断开连接的简单防护
# 流量监控防火墙

基于C++和Boost.Asio实现的简单流量监控防火墙，当连接流量超过阈值时自动断开。

## 功能特性
- 流量监控
- 自动断开超限连接
- 最大连接数限制
- 异步非阻塞IO

## 构建运行
```bash
mkdir build && cd build
cmake ..
make
./firewall

# 依赖
Boost 1.66+
CMake 3.10+
