// 1000db10 RwSetLightState [Global]
// program: RWL21.DLL

int * RwSetLightState(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
                    /* 0xdb10  412  RwSetLightState */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  if ((param_2 != 2) && (param_2 != 1)) {
    FUN_1000cba0(0x2e);
    return (int *)0x0;
  }
  cVar1 = (-(param_1[0x21] == 2) & 2U) + (param_2 == 2);
  if (cVar1 == '\x01') {
    param_1[0x21] = 2;
    FUN_1002c340(param_1);
    iVar2 = RwGetLightOwner((int)param_1);
    FUN_1002c320(iVar2);
    return param_1;
  }
  if (cVar1 != '\x02') {
    return param_1;
  }
  param_1[0x21] = 1;
  FUN_1002c340(param_1);
  iVar2 = RwGetLightOwner((int)param_1);
  FUN_1002c320(iVar2);
  return param_1;
}


