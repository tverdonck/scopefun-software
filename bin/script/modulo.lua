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
	for i = 0,9999,1 do
		data.analog0[i] = data.analog0[(i*2)%9999]
	end
	for i = 0,9999,1 do
		data.analog1[i] = data.analog1[i%24]
	end
	return data
end

-- onConfigure
function onConfigure(hw)
  return hw
end

-- onInit
function onInit(ctx)
  return ctx
end

