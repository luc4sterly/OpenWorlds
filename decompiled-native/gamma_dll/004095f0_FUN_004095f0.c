// 004095f0 FUN_004095f0 [Global]
// program: gamma.dll

int * __thiscall FUN_004095f0(void *this,int param_1,undefined1 param_2)

{
  undefined ****ppppuVar1;
  int iVar2;
  uint *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined ***local_40;
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  int *local_2c;
  undefined1 *local_14;
  
  if (param_1 != 0) {
    if ((param_1 == -1) || (-param_1 - 2U < **(uint **)this)) {
      local_40 = &local_3c;
      local_30 = &local_3c;
      local_3c = &PTR_FUN_0046db74;
      local_2c = local_38;
      iVar2 = FUN_00450b60(0x32);
      local_14 = (undefined1 *)&local_40;
      *local_2c = iVar2;
      local_2c[1] = 0;
      ppppuVar1 = &local_40;
      if (*local_2c != 0) {
        puVar3 = FUN_0044e010(4);
        if (puVar3 != (uint *)0x0) {
          *puVar3 = 1;
        }
        local_2c[1] = (int)puVar3;
        ppppuVar1 = (undefined ****)local_14;
      }
      local_14 = (undefined1 *)ppppuVar1;
      pcVar4 = s_basic_string__append_results_in_s_0046da64;
      puVar5 = (undefined4 *)*local_2c;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        puVar5 = puVar5 + 1;
      }
      *(undefined2 *)puVar5 = *(undefined2 *)pcVar4;
      *local_40 = &PTR_LAB_0046db64;
      FUN_00451670();
    }
    iVar2 = **(int **)this;
    FUN_00408b80(this,iVar2 + param_1,'\x01');
    puVar6 = (undefined1 *)(*(int *)(*(int *)this + 0xc) + iVar2);
    for (; param_1 != 0; param_1 = param_1 + -1) {
      *puVar6 = param_2;
      puVar6 = puVar6 + 1;
    }
  }
  return this;
}


