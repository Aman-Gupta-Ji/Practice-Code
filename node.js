async function getTransactions(userId, locationId, netStart, netEnd) {
    let total = 0;
    let current = 1;
    
    while (true) {
        try {
            const url = `https://jsonmock.hackerrank.com/api/transactions/search?userId=${userId}&page=${current}`;
            const response = await fetch(url);
            const data = await response.json();
            
            if (current === 1) {
                // If no data or no records, return 0
                if (!data || !data.data || data.data.length === 0) return 0;
            }
            
            // Process transactions on current page
            for (const tx of data.data) {
                // Check if transaction matches locationId
                if (tx.location.id === locationId) {
                    // Extract first byte of IP
                    const ipFirstByte = parseInt(tx.ip.split('.')[0]);
                    
                    // Check if IP is in range
                    if (ipFirstByte >= netStart && ipFirstByte <= netEnd) {
                        // Convert amount string to number (remove $ and ,)
                        const amount = parseFloat(tx.amount.replace(/[$,]/g, ''));
                        total += amount;
                    }
                }
            }
            
            // Check if we've processed all pages
            if (current >= data.total_pages) break;
            
            current++;
        } catch (error) {
            console.error('Error fetching data:', error);
            throw error;
        }
    }
    
    // Round to nearest integer and return
    return Math.round(total);
}