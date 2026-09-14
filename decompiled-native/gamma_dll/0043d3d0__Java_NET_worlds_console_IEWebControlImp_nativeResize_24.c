// 0043d3d0 _Java_NET_worlds_console_IEWebControlImp_nativeResize@24 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Java_NET_worlds_console_IEWebControlImp_nativeResize_24
               (int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  int local_30;
  tagRECT local_20;
  
                    /* 0x3d3d0  40  _Java_NET_worlds_console_IEWebControlImp_nativeResize@24 */
  local_30 = 0;
  dVar1 = (double)(param_3 * param_5) * _DAT_00477628;
  dVar2 = (double)(param_4 * param_6) * _DAT_00477628;
  uVar3 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar4 = (**(code **)(*param_1 + 0x178))(param_1,uVar3,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar4 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  puVar5 = (uint *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar4);
  if (puVar5 == (uint *)0x0) {
    puVar5 = FUN_0044e010(0x3c);
    puVar7 = puVar5;
    for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar4,puVar5);
  }
  if (puVar5[2] == 0) {
    return;
  }
  if ((HWND)puVar5[0xb] != (HWND)0x0) {
    SendMessageA((HWND)puVar5[0xb],0x421,0,0);
  }
  if ((HWND)puVar5[0xb] != (HWND)0x0) {
    GetWindowRect((HWND)puVar5[0xb],&local_20);
    local_30 = local_20.bottom - local_20.top;
  }
  FUN_0043e7d0((void *)puVar5[2],0,local_30,(int)ROUND(dVar1),(int)ROUND(dVar2));
  return;
}


