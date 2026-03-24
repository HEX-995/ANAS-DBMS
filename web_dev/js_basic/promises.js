const promiseOne= new Promise(function(resolve,reject){
    setTimeout(function(){
        console.log('async task is complete');
        resolve()//connects to then
    },1000)
})

promiseOne.then(function(){
    console.log('promise is complete');
    
})
/*new Promise(function(resolve,reject){
    setTimeout(function(){
        console.log('async task is complete');
        resolve()//connects to then
    },1000)
}).then(function(){
    console.log('promise is complete');
    
})*/ 