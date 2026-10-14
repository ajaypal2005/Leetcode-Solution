/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
    let persentcount = init;
    function increment() {
        return ++persentcount;
    }
    function reset() {
        return (persentcount = init);
    }
    function decrement() {
        return --persentcount;
    }
    return{increment,reset,decrement};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */