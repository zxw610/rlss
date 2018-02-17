#ifndef PATHREPLAN_OPTIMIZATION_H
#define PATHREPLAN_OPTIMIZATION_H
#include "trajectory.h"
#include "obstacle.h"
#include <vector>
#include "hyperplane.h"

using namespace std;


class problem_data {
  public:
    double current_t;
    double delta_t;
    trajectory* original_trajectory;
    int problem_dimension;
};

class voronoi_data {
  public:
    problem_data* pdata;
    hyperplane plane;
};

class obstacle_data {
  public:
    problem_data* pdata;
    obstacle2D* obs;
};

class optimization {
  public:
    static double objective(const vector<double>& x, vector<double>& grad, void* f_data);
    static double voronoi_constraint(const vector<double>& x, vector<double>& grad, void* v_data);
    static double obstacle_constraint(const vector<double>& x, vector<double>& grad, void* o_data);
};

#endif
