# Derivatives Review
## Basic Rules for Derivatives
**1. Power Rule:**
- For a function $f(x)=x^n$, where $n$ is any real number, the derivative is:
    $$
    \frac{d}{dx}x^n=n \cdot x^{n-1}
    $$
- Example: $\frac{d}{dx}x^3=3 x^{2}$

**2. Constant Rule:**
- The derivative of a constant is always 0:
    $$
    \frac{d}{dx}C=0
    $$
- Example $\frac{d}{dx}7=0$

**3. Sum Rule:**
- If you're taking the derivative of the sum of two functions, take the derivative of each function separately:
    $$
    \frac{d}{dx}[f(x)+g(x)]=f'(x)+g'(x)
    $$
- Example: $\frac{d}{dx}(x^2+3x)=2x+3$

**4. Product Rule:**
- If you're taking the derivative of two multiplied functions, use this rule:
    $$
    \frac{d}{dx}[f(x)\cdot g(x)]=f'(x)\cdot g(x)+f(x)\cdot g'(x)
    $$
- Example: For $f(x)=x^2$ and $g(x)=x^3$,
    $$
    \frac{d}{dx}(x^2\cdot x^3)=2x\cdot x^3+x^2\cdot 3x^2=2x^4+3x^4=5x^4
    $$

**5. Quotient Rule:**
- For a function that is the quotient of two functions, use this:
    $$
    \frac{d}{dx}\left[\frac{f(x)}{g(x)}\right]=\frac{f'(x)g(x)-f(x)g'(x)}{g(x)^2}
    $$
- Example: for $f(x)=x^2$ and $g(x)=x+1$,
    $$
    \frac{d}{dx}\left[\frac{x^2}{x+1}\right]=\frac{2x(x+1)-x^2(1)}{(x+1)^2}=\frac{x^2+2x}{(x+1)^2}
    $$

**6. Chain Rule:**
- If you have a function inside another function, use this:
    $$
    \frac{d}{dx}f(g(x))=f'(g(x))\cdot g'(x)
    $$
- Example: For $f(x)=(3x+1)^2$,
    $$
    \frac{d}{dx}(3x+1)^2=2(3x+1)\cdot 3=6(3x+1)
    $$