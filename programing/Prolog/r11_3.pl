node_depth(t(Label, A, B), Label, 1).
node_depth(t(N, A, B), Label, Depth) :- node_depth(A, Label, Depth_), Depth is Depth_+1.
node_depth(t(N, A, B), Label, Depth) :- node_depth(B, Label, Depth_), Depth is Depth_+1.

node_depth(t(Label, A), Label, 1).
node_depth(t(N, A), Label, Depth) :- node_depth(A, Label, Depth_), Depth is Depth_+1.

node_depth(Label, Label, 1).
