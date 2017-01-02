program IntFact;
var i: LongInt;
var num, max: LongInt;
label restart;
begin
    write('Input your number.');
    Write;
    Readln(num);
    Write;
    max := trunc(sqrt(num));
    //max := num;
    Write(num, ' = ');
    for i:=2 to max do
    begin
        restart:;
            if num mod i = 0 then
            begin
                Write(i);
                Write(' x ');
                num := num div i;
                goto restart;
            end;
    end;
    //if num > max then
        Write(num);
        Writeln;
end.
