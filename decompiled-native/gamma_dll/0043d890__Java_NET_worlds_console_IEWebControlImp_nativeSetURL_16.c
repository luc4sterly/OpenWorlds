// 0043d890 _Java_NET_worlds_console_IEWebControlImp_nativeSetURL@16 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_IEWebControlImp_nativeSetURL_16
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  LPCSTR lpString;
  LPCWSTR lpWideCharStr;
  char *pcVar4;
  int iVar5;
  uint *puVar6;
  char *pcVar7;
  uint *local_5c;
  undefined2 local_44;
  undefined2 uStack_42;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  int local_2c;
  undefined4 uStack_28;
  undefined4 *local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
                    /* 0x3d890  41  _Java_NET_worlds_console_IEWebControlImp_nativeSetURL@16 */
  uVar2 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar3 = (**(code **)(*param_1 + 0x178))(param_1,uVar2,s_nativeIEInstance_00477524,&DAT_00477520);
  if (iVar3 == 0) {
    FUN_00402800(s_nIEWebControlImp_00477538,0x53);
  }
  local_5c = (uint *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar3);
  if (local_5c == (uint *)0x0) {
    local_5c = FUN_0044e010(0x3c);
    puVar6 = local_5c;
    for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar3,local_5c);
  }
  if (local_5c[3] == 0) {
    return;
  }
  lpString = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar3 = lstrlenA(lpString);
  lpWideCharStr = LocalAlloc(0x40,(iVar3 + 1) * 2);
  if (lpWideCharStr == (LPCWSTR)0x0) {
    return;
  }
  *lpWideCharStr = L'\0';
  MultiByteToWideChar(0,0,lpString,-1,lpWideCharStr,iVar3 + 1);
  lstrlenW(lpWideCharStr);
  if (param_4 == 0) {
    (**(code **)(*(int *)local_5c[3] + 0x2c))((int *)local_5c[3],lpWideCharStr,0,0,0,0);
  }
  else {
    pcVar4 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
    uStack_40 = DAT_0049deb4;
    local_3c = DAT_0049deb8;
    uStack_38 = DAT_0049debc;
    _local_44 = CONCAT22((short)((uint)DAT_0049deb0 >> 0x10),8);
    local_3c = Ordinal_2(u_Content_Type__application_x_www__00477630);
    local_34 = DAT_0049dec0;
    uStack_30 = DAT_0049dec4;
    local_2c = DAT_0049dec8;
    uStack_28 = DAT_0049decc;
    iVar3 = -1;
    pcVar7 = pcVar4;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    iVar5 = Ordinal_411(0x11,0,-iVar3 - 2U);
    if (iVar5 == 0) {
      return;
    }
    Ordinal_23(iVar5,&local_24);
    FUN_0044df50(local_24,(undefined4 *)pcVar4,-iVar3 - 2U);
    Ordinal_24(iVar5);
    local_34 = CONCAT22(local_34._2_2_,0x2011);
    local_20 = DAT_0049ded0;
    uStack_1c = DAT_0049ded4;
    uStack_18 = DAT_0049ded8;
    uStack_14 = DAT_0049dedc;
    local_2c = iVar5;
    (**(code **)(*(int *)local_5c[3] + 0x2c))
              ((int *)local_5c[3],lpWideCharStr,&local_20,0,&local_34,&local_44);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_4,pcVar4);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpString);
  LocalFree(lpWideCharStr);
  return;
}


