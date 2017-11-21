-module(test).

-export([main/0]).

main() ->
    io:format("factorial ~w = ~w~n",[1, fac(1)]),
    io:format("factorial ~w = ~w~n",[2, fac(2)]),
    io:format("factorial ~w = ~w~n",[3, fac(3)]),
    init:stop().

fac(0) ->
    1;
fac(N) ->
    N*fac(N-1).


