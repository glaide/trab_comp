program teste (input, output);
var m, n, s : integer;
begin
   read(m,n);
   s:=0;
    if m>n then
      begin
         while m>=n do
            begin
               s:=s+m;
               m:=m-1;
            end;
      end
    else
      begin
         while m<=n do
            begin
               s:=s+m;
               m:=m+1;
            end;
      end;
end.
