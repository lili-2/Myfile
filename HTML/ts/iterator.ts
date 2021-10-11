interface myIteratorResult {
    done: boolean;
    value:any;
}
interface myIterator{
    next() :myIteratorResult;
}
interface myIterable{
    [Symbol.iterator](): myIterator;
}