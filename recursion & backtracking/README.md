1. 当递归时是可以上下左右均遍历搜索的时候，一定记住要维持一个visited数组，或者将已访问的元素改变，不然会进入死循环

    e.g. 向下->向上->向下... 递归会在这两个元素当中一直重复下去

2.  dfs/递归通式

    ```cpp
    Interface(arrays, target) {
      //construct a interface for dps
      //对于dfs本身来说，没有必要在主函数里写循环
      //但是如果题目要求遍历到每个点，那么就需要在主函数里写循环，然后把dfs入口放在循环里
      //dfs可能需要如下的变量，将其传入dfs中
      //dfs(arrays, target, cur_position, cur_value, visited)
      //入口一般从0开始
      dfs(arrays, target, 0, 0)
    }
    
    dfs(xxx) {
      if (判断条件: cur_value == target || cur_position == arrays.size() || meet other restriction)
        do something
      for (当前的所有情况) {
        对原有数据做出改变
        dfs(传入被改变的数据)
        撤回改变，恢复原有数据
      }
    }
    ```
    
3. bfs通式

   ```cpp
   queue<> q;
   //put first element in q
   while (!q.empty()) {
     x = q.top();
     q.pop();
     //改变x这里的值(防止再次被遍历)(详见TIP 1)
     //遍历和q接触的所有元素
     for () {
       if (符合条件) {
         q.push(element);
       }
     }
   }
   ```
   
4. bfs构造的层序遍历

   与bfs的区别在于，bfs每次都把相邻的点放入queue，直至遍历到所有点/达到题目条件
   bfs的层序是要得到每一层的信息(比如有几层)，所以需要作出改变
   
   ```cpp
   queue<> q;
   //put first element in queue
   while (!q.empty()) {
     int len = q.size();
     //通过len来控制每次处理的数据都处于bfs当中的同一层
     for (int i = 0; i < len; i++) {
       //pop the element
       //改变x这里的值(防止再次被遍历)(详见TIP 1)
       //遍历和q接触的所有元素
       for () {
         if (符合条件) {
           q.push(element);
         }
     }
     }
   }
   ```
    
