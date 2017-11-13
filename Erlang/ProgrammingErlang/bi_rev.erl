-module(bi_rev).
-export([rever_b/1]).


rever_b(Bin) ->
    L = [X || <<X:1>> <= Bin],
    lists:reverse(L).
