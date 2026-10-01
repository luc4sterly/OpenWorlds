// 0043db30 _Java_NET_worlds_console_IEWebControlImp_nativePrint@16 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_IEWebControlImp_nativePrint_16
               (int *param_1,undefined4 param_2,undefined4 param_3,HWND param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  tagRECT local_30;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  
                    /* 0x3db30  38  _Java_NET_worlds_console_IEWebControlImp_nativePrint@16 */
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*param_1 + 0x178))(param_1,uVar1,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar2 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  puVar3 = (uint *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar2);
  if (puVar3 == (uint *)0x0) {
    puVar3 = FUN_0044e010(0x3c);
    puVar5 = puVar3;
    for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar2,puVar3);
  }
  if (puVar3[6] == 0) {
    return;
  }
  GetClientRect(param_4,&local_30);
  local_1c = 0;
  local_20 = 0;
  local_14 = local_30.bottom - local_30.top;
  local_18 = local_30.right - local_30.left;
  (**(code **)(*(int *)puVar3[6] + 0xc))
            ((int *)puVar3[6],1,0xffffffff,0,0,0,param_3,&local_20,0,0,0);
  return;
}


