// 00406530 FUN_00406530 [Global]
// programa: gamma.dll

void FUN_00406530(uint *param_1,uint *param_2)

{
  uint *puVar1;
  undefined1 local_28 [24];
  undefined1 *local_10;
  uint *local_c;
  
  local_10 = local_28;
  if (param_1 != (uint *)0x0) {
    local_c = param_1;
    *param_1 = *param_2;
    param_1[1] = (*param_2 + 3) - (*param_2 & 3);
    param_1[2] = 1;
    puVar1 = FUN_0044e010(param_1[1] + 1);
    local_c[3] = (uint)puVar1;
    InitializeCriticalSection((LPCRITICAL_SECTION)(local_c + 4));
    FUN_0044df50((undefined4 *)local_c[3],(undefined4 *)param_2[3],*local_c + 1);
  }
  return;
}


