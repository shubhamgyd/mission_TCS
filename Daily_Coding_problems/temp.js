let logic1 = (a,b,c) => {

    let result = (a + b) % c;
    
    return logic2(result);
    
    };
    
    let logic2 = (a) => {
    
    return (a>0 ? a: a++);
    };
    
    console.log(logic1(10,15,10));