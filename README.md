http://acm.hdu.edu.cn

## 网站上部分题目输出部分不能使用 cout
只能使用 printf

该行无法通过，提示 Wrong Answer
        cout<<fixed<<setprecision(3)<<sum<<"\n";
该行可以通过
        printf("%.3lf\n",sum);
