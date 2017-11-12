-module(myfile).
-export([read/1]).

read(File) ->
    try
        file:read_file(File) of 
        {ok,Co} -> Co;
        {error,_} -> throw({"foo"})

    catch
        %% I haven't figured it out yet
        %% How do i catch the error msg
        wrong:X ->
            {X,erlang:get_stacktrace()}
    end.
