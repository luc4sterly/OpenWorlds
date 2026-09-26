// 004038ad FUN_004038ad [Global]
// programa: gdkup.exe

undefined8 __fastcall
FUN_004038ad(undefined4 param_1,undefined4 param_2,LPCSTR param_3,uint param_4,undefined4 param_5,
            uint param_6)

{
  undefined4 uVar1;
  int iVar2;
  DWORD dwCreationDisposition;
  HANDLE pvVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  uint extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  uint uVar5;
  DWORD dwFlagsAndAttributes;
  uint uVar6;
  DWORD unaff_EDI;
  undefined8 uVar7;
  longlong lVar8;
  DWORD local_24;
  DWORD local_20;
  uint local_1c;
  
  uVar7 = FUN_00404e23(param_1,param_2);
  if ((int)uVar7 != 0) {
    FUN_00403848(extraout_ECX,(int)((ulonglong)uVar7 >> 0x20));
    uVar1 = 0xffffffff;
    goto LAB_00403a5a;
  }
  uVar6 = param_4 & 7;
  FUN_00405552(extraout_ECX,&local_20);
  FUN_0040557e(extraout_ECX_00,&local_24);
  dwFlagsAndAttributes = 0x80;
  if ((DAT_00408b88 == (code *)0x0) ||
     (iVar2 = FUN_00403121(extraout_ECX_01,&DAT_004083ac), iVar2 != 0)) {
    if ((param_4 & 0x20) == 0) {
      if ((param_4 & 0x40) != 0) goto LAB_00403993;
LAB_004039a6:
      dwCreationDisposition = 3;
    }
    else {
      local_1c = param_6 & ~DAT_00408eb0;
      if (((local_1c & 0x100) != 0) && ((local_1c & 0x80) == 0)) {
        dwFlagsAndAttributes = 1;
      }
      if ((param_4 & 0x400) == 0) {
        if ((param_4 & 0x40) == 0) {
          unaff_EDI = 4;
          goto LAB_004039a6;
        }
        unaff_EDI = 2;
LAB_00403993:
        dwCreationDisposition = 5;
      }
      else {
        unaff_EDI = 1;
        dwCreationDisposition = 1;
      }
    }
    pvVar3 = CreateFileA(param_3,local_20,local_24,(LPSECURITY_ATTRIBUTES)0x0,dwCreationDisposition,
                         dwFlagsAndAttributes,(HANDLE)0x0);
    if (pvVar3 == (HANDLE)0xffffffff) {
      pvVar3 = (HANDLE)0xffffffff;
      uVar1 = extraout_ECX_04;
      uVar4 = extraout_EDX_01;
      if ((param_4 & 0x20) != 0) {
        pvVar3 = CreateFileA(param_3,local_20,local_24,(LPSECURITY_ATTRIBUTES)0x0,unaff_EDI,
                             dwFlagsAndAttributes,(HANDLE)0x0);
        uVar1 = extraout_ECX_05;
        uVar4 = extraout_EDX_02;
      }
      if (pvVar3 == (HANDLE)0xffffffff) {
        uVar7 = FUN_00405609(uVar1,uVar4);
        uVar1 = (undefined4)uVar7;
        goto LAB_00403a5a;
      }
    }
    uVar7 = (*(code *)PTR_thunk_FUN_00404e68_00408b44)();
    uVar1 = (undefined4)uVar7;
    lVar8 = FUN_00405618(extraout_ECX_06,(uint)((ulonglong)uVar7 >> 0x20));
    uVar5 = 0;
    uVar4 = extraout_ECX_07;
    if ((int)lVar8 != 0) {
      uVar5 = 0x2000;
    }
  }
  else {
    FUN_00404fe0(extraout_ECX_02,extraout_EDX);
    uVar1 = (*(code *)PTR_thunk_FUN_00404e68_00408b44)();
    (*DAT_00408b88)(0,uVar1,0xffffffff);
    uVar4 = extraout_ECX_03;
    uVar5 = extraout_EDX_00;
  }
  if (uVar6 == 2) {
    uVar5 = uVar5 | 3;
  }
  else if (uVar6 == 0) {
    uVar5 = uVar5 | 1;
  }
  else if (uVar6 == 1) {
    uVar5 = uVar5 | 2;
  }
  if ((param_4 & 0x10) != 0) {
    uVar5 = uVar5 | 0x80;
  }
  if ((param_4 & 0x300) == 0) {
    if (DAT_00408dcd == 0x200) goto LAB_00403a4f;
  }
  else if ((param_4 & 0x200) != 0) {
LAB_00403a4f:
    uVar5 = uVar5 | 0x40;
  }
  FUN_004056ae(CONCAT22((short)((uint)uVar4 >> 0x10),CONCAT11(param_4._1_1_,(char)uVar4)),uVar5);
LAB_00403a5a:
  return CONCAT44(param_2,uVar1);
}


