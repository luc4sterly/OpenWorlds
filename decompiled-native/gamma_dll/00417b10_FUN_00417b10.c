// 00417b10 FUN_00417b10 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_00417b10(float param_1,float param_2,float param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwCreateClump(1,0);
  if (iVar1 != 0) {
    iVar3 = (int)ROUND(_DAT_004703d4 * param_1 + _DAT_004703d8);
    iVar4 = (int)ROUND(_DAT_004703dc * param_2 + _DAT_004703d8);
    uVar2 = (uint)ROUND(_DAT_004703d4 * param_3 + _DAT_004703d8);
    if (iVar3 < 0x20) {
      if (iVar3 < 0) {
        iVar3 = 0;
      }
    }
    else {
      iVar3 = 0x1f;
    }
    if (iVar4 < 0x40) {
      if (iVar4 < 0) {
        iVar4 = 0;
      }
    }
    else {
      iVar4 = 0x3f;
    }
    if ((int)uVar2 < 0x20) {
      if ((int)uVar2 < 0) {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0x1f;
    }
    RwSetClumpData(iVar1,iVar4 << 5 | iVar3 << 0xb | 0x70000000U | uVar2);
    RwAddVertexToClump(iVar1,DAT_004703d0,DAT_004703d0,DAT_004703d0);
    RwSetClumpHints(iVar1,0);
    RwSetClumpState(iVar1,1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1;
}


