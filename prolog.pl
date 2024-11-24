% Facts
parent(john, mary).      % John is a parent of Mary
parent(mary, alice).     % Mary is a parent of Alice
parent(mary, bob).       % Mary is a parent of Bob
parent(george, john).    % George is a parent of John
parent(linda, john).     % Linda is a parent of John

% Rule to define grandparent
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% Rule to define sibling
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.