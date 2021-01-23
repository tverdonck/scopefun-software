require "math"

-- onFrame
function onFrame(data,length)
	return data,length
end

-- onSample
function onSample(sample,ch0,ch1,fun,dig)
	spike = 1000000
	if sample%spike == 0 then 
		ch0  = 500
		ch1  = 250
		print(string.format('%d\n',sample) )
	end
    return sample,ch0,ch1,fun,dig
end

-- onDisplay
function onDisplay(data)
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

-- onFunction
function onFunction(ch0,ch1)
    func = ch0/(math.abs(ch1)+1)
    return func
end
