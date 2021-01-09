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

-- onFunction
function onFunction(ch0,ch1)
	func = ch0+ch1
    return func
end

-- onUpload
function onUpload(gen)
	for i=0,4096,1 do
		gen.analog0[i] = math.sin( i )
		gen.analog1[i] = math.tan( i )
		gen.digital[i] = i % 12
	end
    return gen, 4096
end

