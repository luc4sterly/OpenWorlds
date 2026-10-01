// 00425fb0 Java_NET_worlds_scape_Transform_spin__FFFF [Global]
// program: gamma.dll

/* class _jobject * __stdcall Java_NET_worlds_scape_Transform_spin__FFFF(struct JNIEnv_ *,class
   _jobject *,float,float,float,float) */

_jobject *
Java_NET_worlds_scape_Transform_spin__FFFF
          (JNIEnv_ *param_1,_jobject *param_2,float param_3,float param_4,float param_5,
          float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  undefined4 uVar5;
  float10 fVar6;
  
                    /* 0x25fb0  10
                       ?Java_NET_worlds_scape_Transform_spin__FFFF@@YGPAV_jobject@@PAUJNIEnv_@@PAV1@MMMM@Z
                        */
  uVar5 = (**(code **)(*(int *)param_1 + 400))(param_1,param_2,DAT_0049d24c);
  fVar6 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  fVar1 = (float)fVar6;
  fVar6 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  fVar2 = (float)fVar6;
  fVar6 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  fVar3 = (float)fVar6;
  bVar4 = true;
  if (((byte)((byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 0x40)) {
    bVar4 = false;
  }
  if (bVar4) {
    FUN_00418b10(uVar5,DAT_00471bf4 / fVar1,DAT_00471bf4 / fVar2,DAT_00471bf4 / fVar3);
  }
  FUN_00418a90(uVar5,param_6,param_3,param_4,param_5);
  if (bVar4) {
    FUN_00418b10(uVar5,fVar1,fVar2,fVar3);
  }
  FUN_00412800((int *)param_1,param_2,DAT_0049d25c);
  return param_2;
}


