// 1001ddf0 RwTranslateMatrix [Global]
// program: RWL21.DLL

undefined4 RwTranslateMatrix(float *param_1,float param_2,float param_3,float param_4,int param_5)

{
  undefined4 uVar1;
  
                    /* 0x1ddf0  518  RwTranslateMatrix */
  if (param_1 != (float *)0x0) {
    uVar1 = FUN_1001c820(param_1,param_2,param_3,param_4,param_5);
    return uVar1;
  }
  FUN_1000cba0(1);
  return 0;
}


