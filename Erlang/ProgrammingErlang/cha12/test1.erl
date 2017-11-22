-module(test1).
-export([start/2,stop/0]).


start(Time, Fun) ->
    R = whereis(atomtest),
    if
        R == undefined ->
            register(atomtest, spawn(fun() -> didi(Time, Fun) end));
        true ->
            io:format("there's a process allready running")
    end.

stop() ->
    atomtest ! stop.

didi(Time, Fun) ->
    receive
        stop ->
            void
    after Time ->
            Fun(),
            didi(Time, Fun)
    end.

%% test1:start(2500,fun()->io:format("hello~p~n",[erlang:now()])end).
