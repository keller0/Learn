-module(area_server0).
-export([loop/0]).

loop() ->
    receive
        {rectangle, Width, Ht} ->
            io:format("Area of ractangle is ~p~n",[Width * Ht]),
            loop();
        {square, Side} ->
            io:format("Area of square is ~p~n",[Side * Side]),
            loop()
    end.
