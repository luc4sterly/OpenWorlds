// 0041c970 FUN_0041c970 [Global]
// programa: gamma.dll

int * __thiscall FUN_0041c970(void *this,int *param_1,LPCSTR param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  DWORD dwBytes;
  HGLOBAL pvVar3;
  LPVOID pvVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  char *local_138;
  char *local_130;
  char local_124 [16];
  char local_114 [260];
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  iVar2 = FUN_00401610(param_2,0x8002);
  if (iVar2 == -1) {
    return this;
  }
  FUN_0044da60(iVar2,0,2);
  dwBytes = FUN_0044da60(iVar2,0,1);
  FUN_0044da60(iVar2,0,0);
  pvVar3 = GlobalAlloc(2,dwBytes);
  *(HGLOBAL *)this = pvVar3;
  if (*(int *)this == 0) goto LAB_0041cb82;
  pvVar4 = GlobalLock(*(HGLOBAL *)this);
  *(LPVOID *)((int)this + 4) = pvVar4;
  if ((*(int *)((int)this + 4) == 0) ||
     (uVar5 = FUN_0044dad0(iVar2,*(char **)((int)this + 4),dwBytes), dwBytes != uVar5))
  goto LAB_0041cb82;
  uVar6 = FUN_004181d0(*(undefined4 *)((int)this + 4),dwBytes);
  *(undefined4 *)((int)this + 8) = uVar6;
  if ((*(int *)((int)this + 8) == 0) || (uVar5 = FUN_00419af0(*(int *)((int)this + 8)), uVar5 == 0))
  goto LAB_0041cb82;
  local_130 = local_124;
  if (0x10 < uVar5) {
    local_130 = (char *)FUN_00450b60(uVar5);
  }
  iVar7 = FUN_00419a20(*(undefined4 *)((int)this + 8),local_130,uVar5);
  if (iVar7 != 0) {
    local_138 = local_130;
    do {
      iVar7 = -1;
      pcVar8 = local_138;
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      if (-iVar7 == 2) goto code_r0x0041cb60;
      FUN_0044d6b0(local_114,local_138);
      pcVar8 = FUN_0044d7a0(local_138,'.');
      if (pcVar8 == (char *)0x0) {
        FUN_0044d700(local_114,&DAT_00470a7c);
      }
      (**(code **)(*param_1 + 0x29c))(param_1,local_114);
      FUN_00412800(param_1,param_3,DAT_00489650);
      local_138 = local_138 + -iVar7 + -1;
    } while( true );
  }
LAB_0041cb6d:
  if (0x10 < uVar5) {
    FUN_00451780((undefined4 *)local_130);
  }
LAB_0041cb82:
  FUN_0044da00(iVar2);
  return this;
code_r0x0041cb60:
  *(undefined4 *)((int)this + 0xc) = 1;
  goto LAB_0041cb6d;
}


