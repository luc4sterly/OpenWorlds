// 00417dc0 FUN_00417dc0 [Global]
// program: gamma.dll

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_00417dc0(undefined4 param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  LPVOID pvVar5;
  uint uVar6;
  float10 fVar7;
  float10 fVar8;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_24 [4];
  uint local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_34 = DAT_004703e0;
  local_30 = DAT_004703e4;
  local_2c = DAT_004703e8;
  RwGetCameraLookAt(param_1,&local_34);
  fVar4 = local_34 * local_34 + local_30 * local_30;
  if (fVar4 < (float)_DAT_004703f8) {
    pvVar5 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar5 + 4) = 0x21;
    fVar4 = _DAT_004823b0;
  }
  else {
    fVar4 = SQRT(fVar4);
  }
  fVar7 = (float10)fpatan((float10)local_2c,(float10)fVar4);
  local_24[0] = 1.0;
  local_28 = 0x3f800000;
  dVar1 = (double)-fVar7;
  RwGetCameraViewwindow(param_1,&local_28,local_24);
  fVar8 = (float10)fpatan((float10)local_24[0] * (float10)_DAT_00470400,(float10)_DAT_004703f0);
  dVar2 = (double)fVar8;
  local_14 = 0;
  local_24[3] = 0.0;
  local_24[1] = 0.0;
  local_24[2] = 0.0;
  dVar3 = -dVar2;
  RwGetCameraViewport(param_1,local_24 + 1,local_24 + 2,local_24 + 3,&local_14);
  if ((dVar1 <= dVar3) ||
     ((byte)(dVar1 < dVar2 | (byte)((ushort)((ushort)(NAN(dVar1) || NAN(dVar2)) << 10) >> 8)) != 1))
  {
    uVar6 = 0;
    if ((byte)(dVar1 < dVar3 | (byte)((ushort)((ushort)(NAN(dVar1) || NAN(dVar3)) << 10) >> 8)) == 1
       ) {
      uVar6 = local_14;
    }
  }
  else {
    uVar6 = ((int)((local_14 + 1) - (uint)(local_14 < 0x80000000)) >> 1) -
            (int)ROUND(((float)-fVar7 / local_24[0]) * (float)(int)local_14 + (float)_DAT_00470400);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar6;
}


