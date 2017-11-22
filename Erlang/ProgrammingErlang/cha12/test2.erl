-module(test2).
-export([one/1,start/0]).
%% test spwan's time cost, https://keller0.github.io/spwan20k.html
start() ->
    io:format("N,runtime,wall_clock~n"),
    [one(X) || X <- lists:seq(1,20000)].
one(N) ->
    statistics(runtime),
    statistics(wall_clock),
    L = for(1, N, fun() -> spawn(fun() -> wait() end) end),
    {_, Time1} = statistics(runtime),
    {_, Time2} = statistics(wall_clock),
    lists:foreach(fun(Pid) -> Pid ! die end, L),
    %% pre process's time cost
    %% U1 = Time1 * 1000/N,
    %% U2 = Time2 * 1000/N,

    %% total time cost
    U1 = Time1 * 1000,
    U2 = Time2 * 1000,

    %% process spawn time=~p (~p) microseconds
    io:format("~w,~p,~p~n",[N, U1, U2]).

wait() ->
    receive
        die -> void
    end.

for(N, N, F) ->
    [F()];
for(I, N, F) ->
    [F()|for(I+1, N, F)].


