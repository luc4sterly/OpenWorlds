// 1001de30 RwScaleMatrix [Global]
// programa: RWL21.DLL

undefined4 RwScaleMatrix(float *param_1,float param_2,float param_3,float param_4,int param_5)

{
  undefined4 uVar1;
  
                    /* 0x1de30  361  RwScaleMatrix */
  if (param_1 != (float *)0x0) {
    uVar1 = FUN_1001c940(param_1,param_2,param_3,param_4,param_5);
    return uVar1;
  }
  FUN_1000cba0(1);
  return 0;
}


