nt i = 0; i <= 10; i++)
    {
        if (isOperand(given_data[i]))
        {
            alpha.push(given_data[i]);
        }
        if (isOperator(given_data[i]))
        {
            while (precedence(given_data[i] <= precedence(opstack.topppp())))
            {
                alpha.push(opstack.topppp());
                opstack.pop();
            }
            opstack.push(given_data[i]);
        }
    }