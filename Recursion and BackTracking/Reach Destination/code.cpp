bool reachDestination(int sx, int sy, int dx, int dy) {
    if(sx == dx && sy == dy){
        return true;
    }

    //base condition
    if(sx > dx || sy > dy) {return false;}
    return dx > dy ? reachDestination(sx, sy, dx-dy,dy):
       reachDestination(sx,sy,dx,dy-dx);
}

//Time complexcity : O(log(max(dx.dy)))
//Space complexcity :  O(log(max(dx.dy)))
/*
Analyze the Moves properly based on two conditions, like suppose both a and b are 1 initially.

Condition (a, a+b) => (1, 1+1) => (1, 2) i.e. If we make a move (a, a+b), our new b value will be greater than a.
Condition (a + b, b) => (1 + 1, 1) => (2, 1) i.e. If we make a move (a+b, b), our new a value will be greater than b.
 

So, instead of incrementing sx or sy, we play it safe using kind of reverse engineering 🤯, and decrement dx or dy. Because, instead of trying two directions to move up, we might choose to track downwards on exact 1 path, that we might have took to climb up.

If dx is greater than dy, it means we might have made a previous move as (a + b, a), So, we do reverse of it as(a - b, b)
if dy is greater than dx, it means we might have made a previous move as (a, a + b). So, we do reverse of it as (a, b - a).

*/
