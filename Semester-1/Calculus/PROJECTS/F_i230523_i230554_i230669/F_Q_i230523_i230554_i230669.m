
n=1; % Initializing variable to be used in loop
while n > 0 % Starting loop
    disp('WELCOME TO MMI Software House'); %Displaying names of software house
    disp("Programming Team: ");
    disp("1. Moiz Ansari (23i-0523)");
    disp("2. Minahil Kashif (23i-0554)");
    disp("3. Izza Urooj (23i-0669)");
    disp(" ");
 
    %Waiting for presskey:
    disp("Press any key to continue...");
    disp(" ");
    pause;


    %Taking input:
    diameter = input("Enter the Diameter of the log (in inches): ");
    disp(" ");

    %Declaring variables:
    syms x;

    % Assuming x to be a real variable
    assume(x, 'real');

        
    %Radius of log:
    r = diameter / 2;

    %By using pythagoras theorem:
    %x^2 + y^2 = r^2-----Eq1
    
    %Area of rectangle:
    %A(x) = 4*x*y;
    
    %Using eq 1:
    y(x) = sqrt(power(r,2)-power(x,2));
    %Area:
    A(x) = 4*x*y(x);
    
    %Differntating A w.r.t x:
    y1(x) = diff(A,x);
    
    %Solving (derivative of A(x)) = 0:
    %When A'(x) = 0;
    critical_point1 = solve(y1(x));
    
    %Taking only poitive values:
    result1 = abs(critical_point1);
    
    %Checking range value for critical point 1:
    critical_point1 = abs(critical_point1);
    if critical_point1<=r
        result1 = critical_point1;
    else
        result1 = 0;
    end

    %Printing critical point 1:
    disp("Critical point 1: ");
    disp(result1);
    


    %When A'(x) is not defined:
    critical_point2 = solve(y);

    %Taking only poitive values:
    critical_point2 = abs(critical_point2);

    %Checking range value for critical point 2:
    if critical_point2<=r
        result2 = critical_point2;
    else
        result2 = 0;
    end
    
    %Printing critical point 2:
    disp("Critical point 2: ");
    disp(result2);
    
    %Checking which critical point gives larger area:
    %...
    n1 = A(result1);
    n2 = A(result2);
    
    if n1>n2
        X = result1;
    else
        X = result2;
    end
    %...

    %Caclulating y dimensions:
    Y = sqrt(power(r,2)-power(X,2));
    dim_y = 2*Y;
    dim_x = 2*X;
    
    %Printing Dimensions:
    disp("Dimension x = ");
    disp(dim_x);
    disp("Dimension y = ");
    disp(dim_y);
    
    %Asks user if run program again or not:
    reply = input('Do you wish to run another query? Y/N [Y]:', 's');
    if strcmpi(reply,'Y')   %Ignores case sensitive
        n=1;
    else
        n=0;
    end
end