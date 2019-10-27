#pragma once

template<typename _Vertex>
struct basic_polygon_traits {
    using vertex = _Vertex;
};

template<typename _Vertex, size_t _NumOfPoints>
class basic_polygon {
    static_assert(_NumOfPoints >= 3, "can not create polygon from points when count of them lower then 3");

    using traits = basic_polygon_traits<_Vertex>;

public:
    using vertex = typename traits::vertex;

private:
    vertex points[_NumOfPoints];
};

