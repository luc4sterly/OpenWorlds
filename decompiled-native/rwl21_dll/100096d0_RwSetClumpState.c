// 100096d0 RwSetClumpState [Global]
// program: RWL21.DLL

int RwSetClumpState(int param_1,int param_2)

{
  char cVar1;
  
                    /* 0x96d0  389  RwSetClumpState */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((param_2 != 2) && (param_2 != 1)) {
    FUN_1000cba0(0x2e);
    return 0;
  }
  cVar1 = (-(*(int *)(param_1 + 400) == 2) & 2U) + (param_2 == 2);
  if (cVar1 == '\x01') {
    *(undefined4 *)(param_1 + 400) = 2;
    return param_1;
  }
  if (cVar1 != '\x02') {
    return param_1;
  }
  *(undefined4 *)(param_1 + 400) = 1;
  return param_1;
}


