## How to Use the Addon?
1. Git reposity: ``` git clone https://github.com/wrouruy/napi-math.git ```
2. Import to your JavaScript file: ``` const napiMath = require('./build/Release/napi-math.node'); ```

## Utilization:
```javascript
const napiMath = require('./build/Release/napi-math.node');

console.log(napiMath.sum(10, 10));       // output: 20
console.log(napiMath.multiply(10, 5));   // output: 50
console.log(napiMath.factorial(5));      // output: 120
console.log(napiMath.pow(5, 2));         // output: 25
```

Thanks for reading!
