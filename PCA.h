//
// Created by zzhfeng on 2018/3/7.
//

#ifndef PCA_PCA_H
#define PCA_PCA_H

#pragma once

#include <vector>

/**
 * PCA数据结构
 */
struct PCA_DATA{
    int width;
    float avg;
};

/**
 * PCA类，实现相关功能
 */
class PCA{
private:
    //PCA数据结构
    PCA_DATA pca_data;
    //编码的数据点集合
    std::vector<float> points;
    //数据点总值
    double sum;
    //计数器
    int counter;

public:
    //构造函数
    PCA(int width);
    //读取编码数据点的跨度，即使数量
    int get_width();
    //读取编码后的均值
    float get_avg();
    //加入新的数据点
    bool push(float f);
    //读取编码数据点集合
    std::vector<float> get_points();
    //读取和
    double get_sum();
    //开始
    void start(float f);
    //重置
    void reset();
};

/**
 * 构造函数初始化
 * @param width
 */
PCA::PCA(int width) {
    pca_data.width = width;
    pca_data.avg = 0;
    sum = 0.0;
    counter = 0;
}

/**
 * 读取编码均值结果
 * @return
 */
float PCA::get_avg() {
    return pca_data.avg;
}

/**
 * 读取编码跨度（数量）
 * @return
 */
int PCA::get_width() {
    return pca_data.width;
}

/**
 * 写入数据点
 * @param f
 * @return 返回编码是否完成
 */
bool PCA::push(float f) {
    points.push_back(f);
    sum += f;
    counter += 1;
    if(counter == pca_data.width){
        pca_data.avg = sum / counter;
        return false;
    }
    return true;
}

/**
 * 读取被编码的数据集合
 * @return
 */
std::vector<float> PCA::get_points() {
    return points;
}

/**
 * 读取和
 * @return
 */
double PCA::get_sum() {
    return sum;
}
/**
 * 开始编码
 * @param f
 */
void PCA::start(float f) {
    reset();
    points.push_back(f);
    sum += f;
    counter +=1;
}

/**
 * 重置
 */
void PCA::reset() {
    pca_data.avg = 0.0;
    sum = 0.0;
    counter = 0;
    points.clear();
}

#endif //PCA_PCA_H
