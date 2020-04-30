-- onFrame
function onFrame(data,length)
	return data,length
end

-- onSample
function onSample(sample,ch0,ch1,fun,dig)
    return sample,ch0,ch1,fun,dig
end

-- onDisplay
function onDisplay(data)
	return data
end

-- onConfigure
function onConfigure(hw)
  print( ScopeFun.sfGetYGainA(hw) )
  print( "\n" )
  return hw
end

-- onInit
function onInit(ctx)
  hw = ScopeFun.sfCreateSHardware()
  ScopeFun.sfSetDefault(hw)
  ScopeFun.sfHardwareConfig(ctx,hw)
  return ctx
end

