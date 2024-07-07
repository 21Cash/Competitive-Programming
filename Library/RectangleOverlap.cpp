// Args => (bottomLeft and Top Right Coords of rect1 & rect2)
// Returns Overlap Length, Breadth
pair<long long, long long> findOverlap(long long x1, long long y1, long long x2, long long y2,
                                           long long x3, long long y3, long long x4, long long y4) {
    if (x2 <= x3 || x4 <= x1 || y2 <= y3 || y4 <= y1) {
        return {0LL, 0LL}; 
    }

    long long overlapLength = std::min(x2, x4) - std::max(x1, x3);
    long long overlapBreadth = std::min(y2, y4) - std::max(y1, y3);

    return {overlapLength, overlapBreadth};
}